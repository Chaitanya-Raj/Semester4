<HTML>
<HEAD>
<TITLE> Even </TITLE>
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
      $sum = 0;
      for($i = 1;$i<$num;$i++)
      {
      	if($i%2!=0)
      		$sum=$sum+$i;
      }
      echo "total sum : $sum";
      }
    ?>
</BODY>
</HTML>