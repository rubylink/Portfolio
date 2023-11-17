import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

public class Game{
  private Player m_player; 
  private Dealer m_dealer;
  private Player[] m_playerArray;
  private Card m_pass;


  //default constructor (3 players)
  public Game(){
    m_dealer = new Dealer();
    m_playerArray = new Player[3];
    for (int i = 0; i < 3; ++i){
      m_player = new Player(i + 1, m_dealer);
      m_playerArray[i] = m_player;
      //m_spoons = m_playerArray.length - 1;
    }
  }

  //overloaded constructor (p players)
  public Game(int p){
    m_dealer = new Dealer();
    m_playerArray = new Player[p];
    for (int i = 0; i < p; ++i){
      m_player = new Player(i + 1, m_dealer);
      m_playerArray[i] = m_player;
      //m_spoons = m_playerArray.length - 1;
    }
  }

  //discard method only to be used by last player
  public Card discard(Card pass){
    m_dealer.add(pass); //uses add method from Dealer class to add passed card to the the deck
    return pass;
  }
  
  public String play(){
    while (m_player.getNumSpoons() > 0){
      //goes thorugh each Player to make sure that spoons are still available to be picked up
      for (int l = 0; l < m_playerArray.length; ++l){
        m_player = m_playerArray[l];
        if (m_player.getNumSpoons() == 0){
            break;
          }
        else if (l == 0){
          m_player.takeDeck(); //first player draws from the deck
          m_pass = m_player.takeTurn(); //the Card to be passed is whatever Card the takeTurn method decides not to keep
          m_player.stealSpoon();
          System.out.println(m_player); 
          System.out.println("Have a spoon? " + m_player.getHasSpoon());
          System.out.println(m_player.getNumSpoons() + " spoons left");
        }
        else if (l != 0 && l != m_playerArray.length - 1){
          m_player.takePass(m_pass); //puts the cards passed from the previous player into current players hand
          m_pass = m_player.takeTurn();
          m_player.stealSpoon();
          System.out.println(m_player);
          System.out.println("Have a spoon? " + m_player.getHasSpoon());
          System.out.println(m_player.getNumSpoons() + " spoons left");
        }
        else{
          m_player.takePass(m_pass);
          m_pass = m_player.takeTurn();
          discard(m_pass); //instead of passing the decided Card, it is added back into the Deck
          m_player.stealSpoon();
          System.out.println(m_player);
          System.out.println("Have a spoon? " + m_player.getHasSpoon());
          System.out.println(m_player.getNumSpoons() + " spoons left");
      }
    }
  }
  return "End of Game";
  }

  public int winner(){
    int win = 0;
    for (int i = 0; i < m_playerArray.length; ++i){
      m_player = m_playerArray[i];
      if (m_player.getWinner() == true){ //calls the getWinner accessor from Player class
        win = m_player.getPlayerNum(); //if they are the winner, their player number is recorded
      }
    }
    System.out.print("Winner: Player ");
    return win;
    
  }

  public int loser(){
    int lost = 0;
    for (int i = 0; i < m_playerArray.length; ++i){
      m_player = m_playerArray[i];
      if (m_player.getHasSpoon() == false){ //calls getHasSpoon method from Player class
        lost = m_player.getPlayerNum(); //if player doesnt have spoon, their player number is recorded
      }
    }
    System.out.print("Loser: Player ");
    return lost;
  }

  public String toString(){
    String s = "";
    //s += "Number of Spoons: " + m_spoons;
    s += "\nPlayers: ";
    for (int j = 0; j < m_playerArray.length; ++j){
      s += "\n" + m_playerArray[j].toString();
    }
    return s;
  }
  
  }

  
