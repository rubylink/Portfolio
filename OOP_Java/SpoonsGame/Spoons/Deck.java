import java.util.LinkedList;
import java.util.Random;

public class Deck{
  private LinkedList<Card> m_cards;

  public Deck(){
    m_cards = new LinkedList<Card>();
    for (int i = 2; i < 15; ++i){
      Card heartCard = new Card(i, Card.HEARTS);
      m_cards.add(heartCard);
    }
    for (int i = 2; i < 15; ++i){
      Card spadeCard = new Card(i, Card.SPADES);
      m_cards.add(spadeCard);
    }
    for (int i = 2; i < 15; ++i){
      Card clubCard = new Card(i, Card.CLUBS);
      m_cards.add(clubCard);
    }
    for (int i = 2; i < 15; ++i){
      Card diamondCard = new Card(i, Card.DIAMONDS);
      m_cards.add(diamondCard);
    } 
    
  }

  //print
  public String toString(){
    String s = "";
    for (int i = 0; i < m_cards.size(); ++i){
     s += "\n" + m_cards.get(i);
    }
     return s;
     
     }
  //amount of cards in deck
  public int Size(){
    int size = m_cards.size();
    return size;
  }
  //removes random card from deck and returns
  public Card Deal(){
    Random random = new Random();
    int randIndex = random.nextInt(0, m_cards.size());
    Card randCard = m_cards.get(randIndex);
    m_cards.remove(randIndex);
    return randCard; 
  }

  //had to add this because I need to be able to add it to the Dealer class and implement in Game class with type Dealer
  public Card addCard(Card c){
    m_cards.add(c);
    return c;
  }


  
  


  
}