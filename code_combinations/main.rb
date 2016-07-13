class Matrix
  def initialize(arr)
    @elements = arr
  end

  def generate_submatrices
    submatrices = []
    0.upto(@elements.size - 2).each do |i|
      0.upto(@elements[i].size - 2).each do |j|
        submatrices << Matrix.new([
          [@elements[i][j], @elements[i][j + 1]],
          [@elements[i + 1][j], @elements[i + 1][j + 1]]
          ])
      end
    end
    submatrices
  end

  def has_code
    counters = {
      'c' => 0,
      'o' => 0,
      'd' => 0,
      'e' => 0
    }

    @elements.each do |row|
      row.each do |el|
        counters[el] += 1 if counters[el]
      end
    end

    counters.values.all? { |el| el == 1 }
  end
end

File.open(ARGV[0]).each_line do |line|
  m = line.strip.split(' | ')
  m.each_with_index do |row, index|
    m[index] = row.split('')
  end
  matrix = Matrix.new(m)
  puts matrix.generate_submatrices.map(&:has_code).count(true)
end