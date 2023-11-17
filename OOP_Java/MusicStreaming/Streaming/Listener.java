import java.util.LinkedList; 

public class Listener extends Account{
  public LinkedList<Content> m_favorites;
  private Content m_content; 

  public Listener(){
    super();
    m_favorites = new LinkedList<Content>();
  }

  public Listener(String n){
    super(n);
    m_favorites = new LinkedList<Content>();
  }

/*
  public LinkedList<Content> getFav(){
    return m_favorites;
  }
  */
  public LinkedList<Content> favorite(Content c){
    m_content = c;
    m_favorites.add(m_content);
    return m_favorites;
  }

  public LinkedList<Content> getFavorites(){
    return m_favorites;
  }

  public String toString() {
    String s = super.toString(); // leveraging the parent class's toString method
    /*
    s += "\nThese are your favorites: ";
    for (Content i: m_favorites){
      s += "\n" + i;
    }
    */
    return s;
    
  }
  

  


  
}