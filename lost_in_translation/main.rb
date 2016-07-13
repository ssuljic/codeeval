mapping = {
  a: 'y',
  b: 'h',
  c: 'e',
  d: 's',
  e: 'o',
  f: 'c',
  g: 'v',
  h: 'x',
  i: 'd',
  j: 'u',
  k: 'i',
  l: 'g',
  m: 'l',
  n: 'b',
  o: 'k',
  p: 'r',
  q: 'z',
  r: 't',
  s: 'n',
  t: 'w',
  u: 'j',
  v: 'p',
  w: 'f',
  x: 'm',
  y: 'a',
  z: 'q'
}
File.open(ARGV[0]).each_line do |line|
  line.split('').each do |letter|
    if letter == ' '
      print ' '
    else
      print mapping[letter.to_sym]
    end
  end
  print "\n"
end