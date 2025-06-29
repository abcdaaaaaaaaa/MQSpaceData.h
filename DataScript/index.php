<?php
      include_once 'db.php';
        
      $data1 = $_COOKIE["data1"];
      $data2 = $_COOKIE["data2"];
      $data3 = $_COOKIE["data3"];
      $data4 = $_COOKIE["data4"];
      $data5 = $_COOKIE["data5"];
      $value1 = $_COOKIE["value1"];
      $value2 = $_COOKIE["value2"];
      $value3 = $_COOKIE["value3"];
      $value4 = $_COOKIE["value4"];
      $value5 = $_COOKIE["value5"];

      if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            switch ($data1) {
			case 1:
			$sql = "INSERT INTO MQ135 (Percentile, Air, Temperature, RH, Percentile2, Acetone, Toluene, Alcohol, CO2, NH4, CO)
			        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "')";
            break;
			
			case 3:
			$sql = "INSERT INTO MQ3 (Percentile, Air, Temperature, RH, Percentile2, Alcohol, Benzene, Hexane, LPG, CO, CH4)
			        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "', '" . $value4 . "', '" . $value5 . "', '" . $value6 . "', '" . $value7 . "', '" . $value8 . "', '" . $value9 . "', '" . $value10 . "', '" . $value11 . "')";				
            break;
			}
			
			if ($conn->query($sql) === TRUE) {
			} 
			else {
				echo "Error: " . $sql . "<br>" . $conn->error;
			}
		$conn->close();
      }

?>

<script>
    <?php
        if (isset($data1)) echo "const data1 = $data1;\n\t";
        if (isset($data2)) echo "const data2 = $data2;\n\t";
        if (isset($data3)) echo "const data3 = $data3;\n\t";
        if (isset($data4)) echo "const data4 = $data4;\n\t";
        if (isset($data5)) echo "const data5 = $data5;\n\t";
        if (isset($value1)) echo "const value1 = $value1;\n\t";
        if (isset($value2)) echo "const value2 = $value2;\n\t";
        if (isset($value3)) echo "const value3 = $value3;\n\t";
        if (isset($value4)) echo "const value4 = $value4;\n\t";
        if (isset($value5)) echo "const value5 = $value5;\n\t";
    ?>
</script>