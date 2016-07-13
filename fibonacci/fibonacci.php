<?php

function fibonacci($n) {
  if($n == 0) return 0;
  if($n == 1) return 1;
  $first = 0;
  $second = 1;
  $num = 1;

  for($i = 1; $i < $n; $i++) {
    $num = $first + $second;
    $first = $second;
    $second = $num;
  }

  return $num;
}

$fh = fopen($argv[1], "r");
while (true) {
  $test = fgets($fh);
  if(empty($test)) break;
  echo fibonacci(intval(trim($test))) . "\n";
}

?>
