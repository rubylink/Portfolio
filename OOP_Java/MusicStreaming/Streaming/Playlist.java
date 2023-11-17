import java.util.*;

public class Playlist extends ContentCollections{

  public Playlist(){
    super(); 
  }
  public Playlist(String n, LinkedList<Content> l){
    super(n, l);
  }

  public Content shuffle(LinkedList<Content> check){
    Random rand = new Random();
    int randContent = rand.nextInt(0, check.size());
    Content choose = check.get(randContent);
    choose.play();
    check.remove(choose);
    return choose;
  }
  
  public void playCollect(){
    LinkedList<Content> copy = new LinkedList<>();

    for (Content i: this.m_collect){
      copy.add(i);
    }
    while (copy.size() > 0){
      System.out.println(shuffle(copy));
    }
  }

  public void addSong(Song x){
    this.m_collect.add(x);
  }

  public void addPod(Podcast y){
    this.m_collect.add(y);
  }
  
  public int compareTo(Content o){
    return 0;
  }
  
  public String toString() {
    String s = "";
    s += "Playlist name: " + m_collectionName;
    s += "\nThere are " + m_collect.size() + " items in " + m_collectionName + "\n";
    for (Content i : m_collect){
      s += i; 
  }
    return s;


}
  
}