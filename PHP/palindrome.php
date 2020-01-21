<HTML>
<HEAD>
<TITLE> Palindrome </TITLE>
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
      if ($name == strrev($name))
      echo "$name is palindrome";
      else
      echo"$name is not palindrome";
      }
     ?>
     </BODY>
     </HTML>
 
