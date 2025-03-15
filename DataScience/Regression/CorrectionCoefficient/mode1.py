import numpy as np
from scipy.optimize import curve_fit
import plotly.graph_objects as go
from plotly.subplots import make_subplots
import random

real_x_values = np.array([1, 2, 3, 5])  
degree_x_values = 15 * real_x_values - 25  

MQ = input("Please define the sensor name: ")
input_values = input("Enter the Y (Rs/Ro) values in the following format: (y1, y2, y3, y5), (y1, y2, y3, y5): ")

input_values = input_values.strip('[]')
rh_values = input_values.split('), (')

y_values_RH33 = np.array([float(val) for val in rh_values[0].replace('(', '').replace(')', '').split(',')])
y_values_RH85 = np.array([float(val) for val in rh_values[1].replace('(', '').replace(')', '').split(',')])

def model(x, a, b):
    return a * np.power(x, b)

popt_RH33, _ = curve_fit(model, real_x_values, y_values_RH33)
popt_RH85, _ = curve_fit(model, real_x_values, y_values_RH85)
a_RH33, b_RH33 = popt_RH33
a_RH85, b_RH85 = popt_RH85

def calculate_r_squared(y_true, y_pred):
    residual_sum_of_squares = np.sum((y_true - y_pred) ** 2)
    total_sum_of_squares = np.sum((y_true - np.mean(y_true)) ** 2)
    return 1 - (residual_sum_of_squares / total_sum_of_squares)

R_squared_RH33 = calculate_r_squared(y_values_RH33, model(real_x_values, *popt_RH33))
R_squared_RH85 = calculate_r_squared(y_values_RH85, model(real_x_values, *popt_RH85))

new_x_values = np.linspace(min(real_x_values), max(real_x_values), 1000)
y_pred_RH33_full = model(new_x_values, a_RH33, b_RH33)
y_pred_RH85_full = model(new_x_values, a_RH85, b_RH85)

RH_vals = np.linspace(33, 85, 100)
temp_vals = np.linspace(-10, 50, 100)
temp_grid, RH_grid = np.meshgrid(temp_vals, RH_vals)

def map_value(x, xmin, xmax, newmin, newmax):
    return newmin + (newmax - newmin) * ((x - xmin) / (xmax - xmin))

def calculate_ratio(RH, temp):
    temp_scaled = (temp + 25) / 15
    valuea = map_value(RH, 33, 85, a_RH33, a_RH85)
    valueb = map_value(RH, 33, 85, b_RH33, b_RH85)
    return valuea * np.power(temp_scaled, valueb)

ratio_grid = calculate_ratio(RH_grid, temp_grid)

color_RH33 = '#10AEFD'
color_RH85 = '#FFA500'

fig = make_subplots(
    rows=1, cols=2,
    column_widths=[0.5, 0.5],
    specs=[[{"type": "scatter"}, {"type": "surface"}]],
    subplot_titles=(f"Regression and {MQ} (Rs/Ro) Analysis for RH33 and RH85", "2D Surface Graphics")
)

fig.add_trace(go.Scatter(x=degree_x_values, y=y_values_RH33, mode='markers', marker=dict(color=color_RH33), name='Real Datas for RH33'))
fig.add_trace(go.Scatter(x=15 * new_x_values - 25, y=y_pred_RH33_full, mode='lines', line=dict(color=color_RH33), name=f'RH33 Regression: y = {a_RH33:.4f}x^{b_RH33:.4f} (R²={R_squared_RH33:.4f})'))

fig.add_trace(go.Scatter(x=degree_x_values, y=y_values_RH85, mode='markers', marker=dict(color=color_RH85), name='Real Datas for RH85'))
fig.add_trace(go.Scatter(x=15 * new_x_values - 25, y=y_pred_RH85_full, mode='lines', line=dict(color=color_RH85), name=f'RH85 Regression: y = {a_RH85:.4f}x^{b_RH85:.4f} (R²={R_squared_RH85:.4f})'))

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

print(f"\nRH33: a = {a_RH33:.4f}, b = {b_RH33:.4f}, R² = {R_squared_RH33:.4f}")
print(f"RH85: a = {a_RH85:.4f}, b = {b_RH85:.4f}, R² = {R_squared_RH85:.4f}")

fig.write_html(f"{MQ}_dht_surface.html")
