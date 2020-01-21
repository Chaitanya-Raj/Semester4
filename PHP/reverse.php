<HTML>
<HEAD>
<TITLE> Reverse </TITLE>
</HEAD>
<BODY>
    <form action=" "method="post">
    <lable>enter name=</lable>
    <input type ="text"name="name"><br>
    <input type="submit"name="submit" value="check">
    </form>
    <?php
      if(isset($_POST['submit']))
      {
      $name=$_POST['name'];
      $n = strlen($name)/2;
      $j = strlen($name)-1;
      for($i = 0;$i<$n;$i++)
      {
      	$temp = $name[$i];
      	$name[$i]=$name[$j];
      	$name[$j]=$temp;
      	$j--;
      }
      echo "reverse of the string is $name";
      }
     ?>
</BODY>
</HTML>
 
