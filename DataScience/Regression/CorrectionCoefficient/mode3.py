import numpy as np
from scipy.optimize import curve_fit
import plotly.graph_objects as go
from plotly.subplots import make_subplots

real_x_values = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13])
degree_x_values = 5 * real_x_values - 15

MQ = input("Please define the sensor name: ")
input_values = input("Enter the Y values in the following format: (y1, y2, y3, y4, y5, y6, y7, y8, y9, y11, y10, y11, y12, y13): ")

input_values = input_values.strip('[]')
rh_values = input_values.split('), (')

y_values_RH30 = np.array([float(val) for val in rh_values[0].replace('(', '').replace(')', '').split(',')])
y_values_RH60 = np.array([float(val) for val in rh_values[1].replace('(', '').replace(')', '').split(',')])
y_values_RH85 = np.array([float(val) for val in rh_values[2].replace('(', '').replace(')', '').split(',')])

def model(x, a, b):
    return a * np.power(x, b)

popt_RH30, _ = curve_fit(model, real_x_values, y_values_RH30)
popt_RH60, _ = curve_fit(model, real_x_values, y_values_RH60)
popt_RH85, _ = curve_fit(model, real_x_values, y_values_RH85)
a_RH30, b_RH30 = popt_RH30
a_RH60, b_RH60 = popt_RH60
a_RH85, b_RH85 = popt_RH85

def calculate_r_squared(y_true, y_pred):
    residual_sum_of_squares = np.sum((y_true - y_pred) ** 2)
    total_sum_of_squares = np.sum((y_true - np.mean(y_true)) ** 2)
    return 1 - (residual_sum_of_squares / total_sum_of_squares)

R_squared_RH30 = calculate_r_squared(y_values_RH30, model(real_x_values, *popt_RH30))
R_squared_RH60 = calculate_r_squared(y_values_RH60, model(real_x_values, *popt_RH60))
R_squared_RH85 = calculate_r_squared(y_values_RH85, model(real_x_values, *popt_RH85))

new_x_values = np.linspace(min(real_x_values), max(real_x_values), 1000)
y_pred_RH30_full = model(new_x_values, a_RH30, b_RH30)
y_pred_RH60_full = model(new_x_values, a_RH60, b_RH60)
y_pred_RH85_full = model(new_x_values, a_RH85, b_RH85)

RH_vals = np.linspace(30, 85, 100)
temp_vals = np.linspace(-10, 50, 100)
temp_grid, RH_grid = np.meshgrid(temp_vals, RH_vals)

def interpolate(value, min_value, max_value, target_min, target_max):
    return target_min + (value - min_value) * (target_max - target_min) / (max_value - min_value)

def calculate_ratio(RH, temp):
    temp_scaled = (temp + 15) / 5
    values = []
    
    for i in range(RH.shape[0]):
        for j in range(RH.shape[1]):
            rh = RH[i, j]
            t = temp_scaled[i, j]
            
            if rh <= 60:
                range_a = 30, 60
                a_RH = a_RH30, a_RH60
                range_b = 30, 60
                b_RH = b_RH30, b_RH60
            else:
                range_a = 60, 85
                a_RH = a_RH60, a_RH85
                range_b = 60, 85
                b_RH = b_RH60, b_RH85

            valuea = interpolate(rh, *range_a, *a_RH)
            valueb = interpolate(rh, *range_b, *b_RH)

            result = valuea * np.power(t, valueb)
            values.append(result)

    return np.array(values).reshape(RH.shape)  

ratio_grid = calculate_ratio(RH_grid, temp_grid)

color_RH30 = '#10AEFD'
color_RH60 = '#FF5CCD'
color_RH85 = '#FFA500'

fig = make_subplots(
    rows=1, cols=2,
    column_widths=[0.5, 0.5],
    specs=[[{"type": "scatter"}, {"type": "surface"}]],
    subplot_titles=(f"Regression and {MQ} Ratio Analysis for RH30, RH60, RH85", "2D Surface Graphics")
)

fig.add_trace(go.Scatter(x=degree_x_values, y=y_values_RH30, mode='markers', marker=dict(color=color_RH30), name='Real Datas for RH30'))
fig.add_trace(go.Scatter(x=5 * new_x_values - 15, y=y_pred_RH30_full, mode='lines', line=dict(color=color_RH30), name=f'RH30 Regression: y = {a_RH30:.4f}x^{b_RH30:.4f} (R²={R_squared_RH30:.4f})'))

fig.add_trace(go.Scatter(x=degree_x_values, y=y_values_RH60, mode='markers', marker=dict(color=color_RH60), name='Real Datas for RH60'))
fig.add_trace(go.Scatter(x=5 * new_x_values - 15, y=y_pred_RH60_full, mode='lines', line=dict(color=color_RH60), name=f'RH60 Regression: y = {a_RH60:.4f}x^{b_RH60:.4f} (R²={R_squared_RH30:.4f})'))

fig.add_trace(go.Scatter(x=degree_x_values, y=y_values_RH85, mode='markers', marker=dict(color=color_RH85), name='Real Datas for RH85'))
fig.add_trace(go.Scatter(x=5 * new_x_values - 15, y=y_pred_RH85_full, mode='lines', line=dict(color=color_RH85), name=f'RH85 Regression: y = {a_RH85:.4f}x^{b_RH85:.4f} (R²={R_squared_RH85:.4f})'))

fig.add_trace(go.Surface(x=temp_grid, y=RH_grid, z=ratio_grid, colorscale='Viridis', showscale=True, hoverinfo='x+y+z', colorbar=dict(thickness=15, len=0.75, y=0.5, yanchor="middle")))

fig.update_layout(
    template='plotly_dark',
    autosize=True,  
    scene=dict(
        camera=dict(
            eye=dict(x=0, y=-2, z=0.088)
        ),
        xaxis=dict(title="Temperature (°C)"),
        yaxis=dict(title="Humidity RH"),
        zaxis=dict(title="CorrectionCoefficient")
    ),
    showlegend=True,
    margin=dict(l=70, r=70, t=70, b=70),
    coloraxis_colorbar=dict(
        thickness=15,
        tickvals=np.linspace(np.min(ratio_grid), np.max(ratio_grid), 100)
    )
)

fig.update_xaxes(title_text="Temperature (°C)")
fig.update_yaxes(title_text="Rs/Ro")

print(f"\nRH30: a = {a_RH30:.4f}, b = {b_RH30:.4f}, R² = {R_squared_RH30:.4f}")
print(f"RH60: a = {a_RH60:.4f}, b = {b_RH60:.4f}, R² = {R_squared_RH60:.4f}")
print(f"RH85: a = {a_RH85:.4f}, b = {b_RH85:.4f}, R² = {R_squared_RH85:.4f}")

fig.write_html(f"{MQ}_dht_surface.html")
