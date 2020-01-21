<HTML>
<HEAD>
<TITLE> Lower </TITLE>
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
      $lower = true;
      for($i = 0;$i<strlen($name);$i++)
      {
      	if(!ctype_lower($name[$i]))
      		$lower=false;
      }
      if($lower)
      	echo "string is lowercase";
     else
     	echo "string is not lowercase";
      }
     ?>
</BODY>
</HTML>
 
