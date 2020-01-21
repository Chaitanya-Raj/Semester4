<HTML>
<HEAD>
<TITLE> Add two number </TITLE>
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
      $fact = 1;
      for($i = $num;$i>1;$i--)
      	$fact = $fact * $i;
      echo "Factorial = $fact";
      }
     ?>
     </BODY>
     </HTML>
 
