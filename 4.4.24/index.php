<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Document</title>
</head>

<body>

    <form action="index.php" method="POST">
        <select name="customers" id="customers">
            <?php
        $conn = mysqli_connect("localhost", "root", "", "classicmodels");

        $query = "SELECT customerNumber, customerName FROM classicmodels.customers WHERE customerName LIKE 'a%';";

        $result = mysqli_query($conn, $query);

        if(isset($_POST['Submit'])){
        while($row = mysqli_fetch_row($result)){
                echo "<option value=". $row[0] . ">$row[1]</option>";
        }
                
            
        }
        
        mysqli_close($conn)
        ?>


        </select>
        <input type="submit" value="Submit" name="Submit">
    </form>


   
</body>

</html>