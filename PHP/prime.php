<HTML>
<HEAD>
<TITLE> Prime </TITLE>
</HEAD>
<BODY>
    <form action=" "method="get">
    <lable>Enter num=</lable>
    <input type ="text"name="num"><br>
    <input type="submit"name="submit">
    </form>
    <?php
      if(isset($_GET['submit']))
      {
      $num=$_GET['num'];
      $prime = true;
      for($i = 2;$i<=$num/2;$i++)
      {
      	if($num%$i==0)
      	{	
      		$prime = false;
      		break;
      	}
      }
      if($prime == true)
      	echo "$num is prime";
      else
      	echo "$num is not prime";
      }
     ?>
</BODY>
</HTML>
 
