import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
  words = test.split(' ')
  capitalized_words = [word[:1].upper() + word[1:] for word in words]
  sys.stdout.write(' '.join(capitalized_words))

test_cases.close()