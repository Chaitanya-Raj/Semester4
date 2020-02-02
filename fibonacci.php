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
      function fib($x){
          if($x==1||$x==2)
            return $x-1;
          else
            return(fib($x-1)+fib($x-2));
        }
        echo "The fibonacci series : ";
        for($i = 1; $i<=$num;$i++)
            echo " ",fib($i);
      }
     ?>
</BODY>
</HTML>
 
