<?
    // ajax post til at gemme med :)

    ini_set('display_errors',1);
    ini_set('display_startup_errors',1);
    error_reporting(-1);

    $data = $_POST['img'];

    list($type, $data) = explode(';', $data);
    list(, $data)      = explode(',', $data);
    $data = base64_decode($data);

    $good = file_put_contents('./drawings/works.png', $data);
    echo "status $good";
?>
