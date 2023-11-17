import java.util.*;

public abstract class ContentCollections implements Comparable<Content>{
  protected String m_collectionName;
  protected LinkedList<Content> m_collect;

  public ContentCollections(){
    m_collectionName = null;
    m_collect = new LinkedList<>();
  }
  public ContentCollections(String cn, LinkedList<Content> co){
    m_collectionName = cn;
    m_collect = co;
  }

  public int compareTo(LinkedList<Content> c) {
    int ret;
    if (this.m_collect.size() > c.size()) {
      ret = 1;
    } 
    else if (this.m_collect.size() < c.size()) {
      ret = -1;
    } 
    else {
      ret = 0;
    }
    return ret;
  }

  /*
  public void shuffle(){
    Random rand = new Random();
    int randContent = rand.nextInt(0, m_burner.size());
    Content c = m_collect.get(randContent);
    c.play();
  }
  */

  public abstract void playCollect();



  
}