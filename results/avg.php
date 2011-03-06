<?
// Which MySQL table to insert to
$table = "random";

// Insert into database
$valuetext = "NULL";
$mysql_access = mysql_connect("localhost", "priceypi_cmps160", "5pZVxWa@{NH0");
mysql_select_db("priceypi_cs160rank", $mysql_access);
for($i=0; $i<=877; $i++) {
	$col = "img" . $i;
	$query = "SELECT AVG({$col}) AS average FROM random";
	$result = mysql_query($query, $mysql_access);
	
	$array = mysql_fetch_array($result);
	echo "<ranks><index>" . $i . "</index><rank>" . $array[0] . "</rank>\n";
}

mysql_close($mysql_access);

// mail("ksamii@ucsc.edu", "[CMPS 160] Test Image Ranking", $valuetext);

?>
