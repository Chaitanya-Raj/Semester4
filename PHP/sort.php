<HTML>
<HEAD>
<TITLE> Sort </TITLE>
</HEAD>
<BODY>
    <?php
    
      $arr = array(5,4,3,2,1);
      
      echo "Unsorted array is <br>";
      print_r($arr);
      
      $size = count($arr)-1;
      for($i=0;$i<$size;$i++){
      	for($j=0;$j<$size-$i;$j++){
      		$k=$j+1;
      		if($arr[$k]<$arr[$j]){
      			$temp = $arr[$k];
      			$arr[$k]=$arr[$j];
      			$arr[$j]=$temp;
      		}
      	}
      }
      
      echo "<br><br>Sorted array is <br>";
      print_r($arr);
      
      ?>
</BODY>
</HTML>
 
