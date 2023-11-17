public class Card{
  private int m_value;
  //j = 11, q = 12, k =13, a=14
  private int m_suit;
  //hearts 0, spades 1, clubs 2, diamonds 3
  
  //values
  public static final int JACK = 11;
  public static final int QUEEN = 12;
  public static final int KING = 13;
  public static final int ACE = 14;
  //suit
  public static final int HEARTS = 0;
  public static final int SPADES = 1;
  public static final int CLUBS = 2;
  public static final int DIAMONDS = 3;

  
  //defualt
  public Card(){
    m_value = 14;
    m_suit = 1; 
  }
  //full
  public Card(int v, int s){
    m_value = v;
    m_suit = s;
  }
  //copy constructor
  public Card(Card cardtocopy){
    m_value = cardtocopy.m_value;
    m_suit = cardtocopy.m_suit;
  }
  
  //accessor
  public int getValue() {
    return m_value;
  }
  public int getSuit() {
    return m_suit;
  }

  //modifer
  public void setValue(int v) {
    m_value = v;
  }
  public void setSuit(int s) {
    m_suit = s;
  }
  
  //toString
  public String toString(){
    
    String valSt = "";
    int valNum = 0;
    String suit = "";
    String s = "";
    
   //value
    if (m_value == 11){
      valSt = "Jack";
    }
    else if (m_value == 12){
      valSt = "Queen";
    }
    else if(m_value == 13){
      valSt = "King"; 
    }
    else if (m_value == 14){
      valSt = "Ace";
    }
    else{
      valNum = m_value;
    }
    
    //suit
    if (m_suit == 0){
      suit = "Hearts";
    }
    else if(m_suit == 1){
      suit = "Spades"; 
    }
    else if (m_suit == 2){
      suit = "Clubs";
    }
    else{
      suit = "Diamonds";
    }

    //printing
    if (m_value < 11){
      s += valNum + " of "+ suit;
      }
    else{
      s += valSt + " of " + suit;
    }
    return s; 
  }
  //equals
  public boolean equals (Object o){
    if(!(o instanceof Card)){
      return false;
    }
    Card c = (Card) o;
    return (this.m_value == c.m_value && this.m_suit == c.m_suit);
  }
  
  
}