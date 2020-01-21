<html>
<head>
<title>1st HTML Page</title>
</head>
<body>
<hr>
<?php
$a = array(5,2,1,7);
rsort($a);
for($i=0;$i<4;$i++)
echo " $a[$i]";
?>
</body>
</html>
