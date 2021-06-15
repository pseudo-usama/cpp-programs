<?php
    $conn = mysqli_connect('localhost', 'root', '', 'map');
?>

<?php
    if (isset($_REQUEST['lat'])) {
        $search_query = "
            SELECT *, ( 3959 * acos( cos( radians($_REQUEST[lat]) ) * cos( radians( lat ) ) * cos( radians( lng ) - radians(" . $_REQUEST['lng'] . ") ) + sin( radians(" . $_REQUEST['lat'] . ") ) * sin( radians( lat ) ) ) ) AS distance
            FROM place HAVING distance < 5
        ";

        $results = mysqli_query($conn, $search_query);
        while ($result = mysqli_fetch_assoc($results)) {
            echo "
                <div class='result'>
                    <p>$result[name]</p>
                    <img src='$result[icon]'>
                </div>
            ";
        }
    }
?>