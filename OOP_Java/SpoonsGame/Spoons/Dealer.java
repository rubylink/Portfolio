import java.util.LinkedList;
import java.util.Random;

public class Dealer{
  private Deck m_deck;

  public Dealer(){
    m_deck = new Deck();
  }
  
/*created this so that it could be implemented in my takeDeck method
Deal() doesnt work because it is only used in type deck, and Deals()
doesn't work because it returns a linked list, i only want one Card
  */
  public Card removeRand(){
    Card get = this.m_deck.Deal();
    return get;
  }
  
/*created this so that it could be implemented in my discard method.
Must implement so that a card can be added to type Dealer
  */
  public Card add(Card c){
    m_deck.addCard(c);
    return c;
  }


  public LinkedList<Card> Deals(int n){
    LinkedList<Card> dealed = new LinkedList<Card>();
  for (int i = 0; i < n; ++i){
    dealed.add(this.m_deck.Deal());
  }
    return dealed;
}
  public int size(){
    int deckSize;
    deckSize = m_deck.Size();
    return deckSize;
  }
  
  public String toString(){
    return m_deck.toString();
  }
  
}




  
