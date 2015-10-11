<?
ini_set('display_errors',1);
ini_set('display_startup_errors',1);
error_reporting(-1);

// sql setup

$user = "lilbigbro";
$host = "localhost";
$dbname = "futurehacks";
$pass = "Q8BpJ9cBNvpmLRnc";

// PDO sql options
$opt = array(
    PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC
);

$db = new PDO("mysql:host=$host;dbname=$dbname;", $user, $pass, $opt);

$idToGet = $_GET['id'];

if($idToGet != null && $idToGet != ""){
    $sql = 'SELECT insightState FROM customer WHERE usr_id = "'.$idToGet.'"';
    $state = "";
    foreach ($db->query($sql) as $row) {            
        $state = $row['insightState'];
    }     
    

    echo $state;
}