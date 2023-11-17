import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

public class Player{
  private Dealer m_deck;
  private LinkedList<Card> m_hand;
  private int m_playerNum; 
  private HashMap<Integer, Integer> m_handMatches;
  private ArrayList<Card> m_matchArr;
  private ArrayList<Card> m_noMatchCards;
  private boolean m_noticeSpoon;
  private boolean m_hasSpoon;
  private boolean m_winner;

  public static int m_numSpoons = -2; //number of spoons is always one less than the number of players
  public static int m_numPlayers = -1;
  
  
  public Player(int p, Dealer d) {
    m_deck = d;
    m_playerNum = p;
    m_hand = new LinkedList<>();
    m_hand = m_deck.Deals(4);
    m_handMatches = new HashMap<>();
    m_hasSpoon = false;
    m_numSpoons += 1; //every time a Player is created, m_numSpoons increases by one
    m_numPlayers += 1; 
    m_winner = false; //initialize no winner
  }
  //draws one card randomly from the deck and adds it to Player's hand
  public Card takeDeck(){
    Card deckCard = m_deck.removeRand(); //uses removeRand methond created in Dealer class
    m_hand.add(deckCard);
    return deckCard;
  }
  //takes in a Card and adds it to the Player's hand
  public Card takePass(Card pass){
    m_hand.add(pass);
    return pass;
  }

  public HashMap<Integer, Integer> findMatches(){
    
    HashMap<Integer, Integer> matches = new HashMap<>(); //keys are card values, and values are num of matches (1-3)
    ArrayList<Card> noMatchCards = new ArrayList<>(); //same as m_noMatchCards but only accessable in method
    ArrayList<Card> matchArr = new ArrayList<>(); //same as m_matchArr but only accessable in method
    Card getCardI; 
    int iCardVal;

    /* 
      DOUBLE FOR LOOP:
      Takes the value of the first card and checks it with the value of each card after it. 
      If there are matches, they are recorded in matchArr and matches. 
      If a match has already been recorded, it is skipped so that there aren't duplicates or overrides
      If there are no matches, it is recorded in noMatchCards

      Method arrays are only accessible inside the array and reset each time it is called 
    */
    
    int length = m_hand.size();
    for (int i = 0; i < length-1; ++i){
      int counter = 0;
      getCardI = m_hand.get(i); //get first card
      iCardVal = getCardI.getValue(); //get value of first card
      if (matches.containsKey(iCardVal)){ //checks to see if that card already has a match recorded
        counter += 1; //if card already has a match, inner for loop isnt executed
      }
      else{
        for (int j = i + 1; j < length; ++j){
          Card getCardJ = m_hand.get(j); //gets the rest of the Cards through each iteration
          int jCardVal = getCardJ.getValue();
          if (jCardVal == iCardVal){ //compares the values
            counter += 1;
          }
        }
        //records matches
        if (counter > 0 ){ 
          matches.put(iCardVal, counter);
          matchArr.add(getCardI);
      }
        //records non matches
        else{
          noMatchCards.add(getCardI);
      }
      }
    }
    /*
    Because the last Card isn't compared to anything after it, it won't be added to 
    an array in the for loop. this checks if it has a match or not and adds it to the 
    corresponding array.
      */
    getCardI = m_hand.get(length-1);
    iCardVal = getCardI.getValue();
    if (matches.containsKey(iCardVal)){
      int counter = 0;
    }
    else{
      noMatchCards.add(getCardI);
    }


    m_matchArr = matchArr;
    m_noMatchCards = noMatchCards;
    m_handMatches = matches;
    return m_handMatches;
  }


  public Card Decision(){
    Random random = new Random();
    Card randCard;
    Card getRid = new Card();
    //if there is only one Card without a match, that Card is chosen
    if (m_noMatchCards.size() == 1){
      randCard = m_noMatchCards.get(0);
      getRid = randCard;
    }
    //if there are multiple non mathces, one is randomly chosen
    else if(m_noMatchCards.size() != 0) {
      int randIndex = random.nextInt(0, m_noMatchCards.size() - 1);
      randCard = m_noMatchCards.get(randIndex);
      getRid = randCard;
    }
    //if all are matched, a Card with the fewest pairs is chosen
    else{
      int min = 4;
      for (int k = 0; k < m_matchArr.size() - 1; ++k) {
        Card gotCard = m_matchArr.get(k);
        int gotVal = gotCard.getValue();
        if (m_handMatches.get(gotVal) < min){ //sets lowest value (num matches) to min
          min = gotVal;
          getRid = gotCard;
        }
        else{
          k += 0;
        }
    }
    }
    return getRid;
  
  }


  public Card takeTurn(){
  
    //if the number of spoons hasn't changed, do nothing
    if (m_numSpoons == m_numPlayers - 1){
      m_noticeSpoon = false;
    }
    //if the number of spoons has decreased, 1/3 chance player will notice 
    else{
      Random rand = new Random();
      int randChance = rand.nextInt(1, 3);
      if (randChance == 1){
        m_noticeSpoon = true;
      }
      else{
        m_noticeSpoon = false;
      }
    }
    
    findMatches();
    Card drop = Decision();
    m_hand.remove(drop);
    return drop;
  }

  public boolean stealSpoon(){
    int check = 0;
    //if they dont notice a spoon has been taken, check to see if they have a winning hand
    if (m_noticeSpoon == false){
      Card getOne = m_hand.get(0);
      int oneVal = getOne.getValue();
      for (int m = 1; m < 4; ++m){
        Card getRest = m_hand.get(m);
        int otherVal = getRest.getValue();
        if (oneVal == otherVal){
          check +=1;
        }
        else{
          check += 0;
        }
      
      }
      //if they have a winning hand, take a spoon and m_winner set to true
      if (check == 3 && this.m_hasSpoon != true){
        m_numSpoons -= 1;
        m_hasSpoon = true;
        m_winner = true;
        System.out.print("\nPLAYER " + m_playerNum + " IS THE WINNER!!!");
      }
      else{
        m_noticeSpoon = false;
      }
    }
    //if they notice a spoon is gone and they already have a spoon, nothing happens
    else if (m_noticeSpoon == true && this.m_hasSpoon == true){
      m_hasSpoon = true;
    }
    //if they notice it's gone and dont have a spoon, take one
    else{
      m_numSpoons -= 1;
      m_hasSpoon = true;
    }
  return m_hasSpoon;
  }

  //accessors
  public int getPlayerNum(){
    return m_playerNum;
  }
  public int getNumSpoons(){
    return m_numSpoons;
  }
  public boolean getNoticeSpoon(){
    return m_noticeSpoon;
  }
  public boolean getHasSpoon(){
    return m_hasSpoon;
  }
  public boolean getWinner(){
    return m_winner;
  }
  public HashMap<Integer,Integer> getMatches(){
    return m_handMatches;
  }
  
  //Mutators
  public void setNumSpoons(int s){
    m_numSpoons = s;
  }
  public void setNoticeSpoon(boolean b){
    m_noticeSpoon = b;
  }
  public void setHasSpoon(boolean b){
    m_hasSpoon = b;
  }
  
  public String toString(){
    String s = "";
    s += "\nPlayer Number: " + m_playerNum;
    s += "\nHand: " + m_hand;
    
    return s;
  }
    
}

  


