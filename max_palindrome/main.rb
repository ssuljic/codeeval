def is_palindrome(number)
  number.to_s == number.to_s.reverse
end

def is_prime(number)
  2.upto(number - 1).each do |i|
    return false if number % i == 0
  end
  true
end

1000.downto(1).each do |i|
  if is_palindrome(i) && is_prime(i)
    puts i
    break
  end
end