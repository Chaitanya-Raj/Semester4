<HTML>
<HEAD>
<TITLE> Add two number </TITLE>
</HEAD>
<BODY>
    <form action=" "method="get">
    <lable>enter num1=</lable>
    <input type ="text"name="num1"><br>
    <lable>enter num2=</lable>
    <input type="text"name="num2"/><br>
    <input type="submit"name="submit" value="add">
    </form>
    <?php
      if(isset($_GET['submit']))
      {
      $num1=$_GET['num1'];
      $num2=$_GET['num2'];
      $total=$num1+$num2;
      echo "totalvalue=$total";
      }
     ?>
     </BODY>
     </HTML>
 
