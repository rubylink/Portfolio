import java.util.*;

public class Album extends ContentCollections{

  public Album(){
    super();
  }
  public Album(String na, LinkedList<Content> ll){
    super(na, ll);
  }

  public void playCollect(){
    for (Content al : this.m_collect){
      al.play();
      System.out.println(al);
    }
    
  }
  
// gives me an error unless I add this
  public int compareTo(Content o){
   return 0;
  }

  public String toString() {
    String s = "";
    s += "Album name: " + m_collectionName;
    s += "\nThere are " + m_collect.size() + " songs in this album";
    s += "\nSongs: ";
    for (Content al : m_collect){
      s += "\n" + al; 
  }
    return s;
}

}