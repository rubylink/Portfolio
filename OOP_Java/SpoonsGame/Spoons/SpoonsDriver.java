public class SpoonsDriver{
  public static void main(String[] args){
    Dealer dealing = new Dealer();
    Player p1 = new Player(1, dealing);
    //Player p2 = new Player(2, dealing);
    //Card test = new Card();
    //Player p3 = new Player(3, dealing);
 
    //System.out.println(p1);
    //System.out.println(p2);
    //System.out.println(p3);
    //System.out.println(p1.findMatches());
    //System.out.println(p2.findMatches());
    //System.out.println(p1.Decision());

    //System.out.println(p1.takeDeck());
    //System.out.println(p1.takePass());
    //System.out.println(p1.takeTurn());
    //System.out.println(p1.stealSpoon());

    //System.out.println(p2.takePass(test));
    //System.out.println(p2.takeTurn());
    //System.out.println(p2.stealSpoon());
    //System.out.println(p2.getSpoons());


    Game game = new Game(4);
    //System.out.println(game);
    System.out.println(game.play());
    System.out.println(game.winner());
    System.out.println(game.loser());
    
  }
}