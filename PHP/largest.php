<HTML>
<HEAD>
<TITLE> Largest </TITLE>
</HEAD>
<BODY>
    <form action=" "method="post">
    <lable>enter num1=</lable>
    <input type ="text"name="num1"><br>
    <lable>enter num2=</lable>
    <input type="text"name="num2"/><br>
    <lable>enter num3=</lable>
    <input type="text"name="num3"/><br>
    <input type="submit"name="submit" value="check">
    </form>
    <?php
      if(isset($_POST['submit']))
      {
      $num1=$_POST['num1'];
      $num2=$_POST['num2'];
      $num3=$_POST['num3'];
      if($num1 > $num2 && $num1 > $num3)
      echo "Greatest number is :$num1<br>";
       elseif($num2 > $num1 && $num2 > $num3)
      echo "Greatest number is :$num2<br>";
       else
      echo "Greatest number is :$num3";
      }
     ?>
     </BODY>
     </HTML>
 
