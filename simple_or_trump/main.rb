class Card
  attr_accessor :num, :color

  def initialize(string)
    @num = string[0..-2]
    @color = string[-1..-1]
  end

  def rank
    return num.to_i if num.to_i.to_s == num
    ranks = {
      'J' => 11,
      'Q' => 12,
      'K' => 13,
      'A' => 14
    }
    ranks[num]
  end

  def puts_greater(card, deuce)
    if deuce == self.color && deuce == card.color
      if self.rank > card.rank
        puts self
      else
        puts card
      end
      return
    end
    if (self.rank < card.rank || card.color == deuce) && self.color != deuce
      puts card
      return
    end

    if (self.rank > card.rank || self.color == deuce) && card.color != deuce
      puts self
      return
    end

    if self.rank == card.rank && card.color != deuce && self.color != deuce || self.rank == card.rank && card.color == deuce && self.color == deuce
      puts "#{self} #{card}"
      return
    end

    puts "NOT FOUND #{self} #{card} #{deuce}"
  end

  def to_s
    "#{num}#{color}"
  end
end

File.open(ARGV[0]).each_line do |line|
  parts = line.split(' ')
  hand1 = parts.first
  hand2 = parts[1]
  deuce = parts.last
  card1 = Card.new(hand1)
  card2 = Card.new(hand2)
  # puts "#{card1} #{card2} #{deuce}"
  card1.puts_greater(card2, deuce)
  # puts "#########"
end