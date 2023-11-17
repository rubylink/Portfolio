
public abstract class Content implements Comparable<Content>{
  protected String m_title; 
  protected String m_artist;
  protected int m_numStreams; 

  public Content(){
    m_title = null;
    m_artist = null; 
    m_numStreams = 0;
  }

  public Content(String t, String a){
    m_title = t;
    m_artist = a; 
    m_numStreams = 0;
  }

  public String getTitle(){
    return m_title;
  }
  public String getArtist(){
    return m_artist;
  }
  public int getSteams(){
    return m_numStreams;
  }

  public void setTitle(String t){
    m_title = t;
  }
  public void setArtist(String a){
    m_artist = a;
  }

  public boolean equals(Object o) {
    if (this == o) { // checks memory locations
      return true;
    }
    if (!(o instanceof Content)) {
      return false;
    }
    Content c = (Content) o;
    return m_title.equals(c.m_title) && m_artist.equals(c.m_artist);

  }

  public int compareTo(Content c) {
    int ret;
    if (this.m_numStreams > c.m_numStreams) {
      ret = 1;
    } 
    else if (this.m_numStreams < c.m_numStreams) {
      ret = -1;
    } 
    else {
      ret = 0;
    }
    return ret;
  }

  public abstract void play();

  public String toString() {
    String s = "";
    s += "\nTitle: " + m_title + "\n";
    s += "Artist: " + m_artist + "\n";
   // s += "The number of times played is: " + m_numStreams + "\n";
    return s;
  }

  

  

  










  


  
}