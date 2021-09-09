<?php
    $conn = mysqli_connect('localhost', 'root', '', 'map');

    if (isset($_REQUEST['id'])) {
        $query = "
            INSERT INTO `place`
            VALUES ('$_REQUEST[id]', '$_REQUEST[name]', '$_REQUEST[lat]', '$_REQUEST[lng]', '$_REQUEST[icon]');                
        ";        
        
        if (mysqli_query($conn, $query)) {
            echo "0";
        } else {
            echo "1";
        }       
    }
?>