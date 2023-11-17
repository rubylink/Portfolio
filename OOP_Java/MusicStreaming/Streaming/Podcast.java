import java.util.LinkedList; 

public class Podcast extends Content{
  protected int m_numEpisode;
  //private LinkedList<Podcast> m_played;

  public Podcast(){
    super();
    m_numEpisode = 0;
  }

  public Podcast(String t, String a, int n){
    super(t,a);
    m_numEpisode = n;
  }

  public String getPodTitle(){
    return m_title;
  }

  public boolean equals(Object o) {
    if (this == o) { // checks memory locations
      return true;
    }
    if (!(o instanceof Podcast)) {
      return false;
    }
    Podcast p = (Podcast) o;
    return super.equals(o) && m_numEpisode == p.m_numEpisode;
  }
  
  public void play() { 
    this.m_numStreams += 1;  
    //System.out.println("You have played this podcast " + m_numStreams + " times");
  }

  public String toString() {
    String s = super.toString(); 
    s += "Episode number: " + m_numEpisode + "\n";
    s += "Number of streams: " + m_numStreams + "\n";
    return s;
  }

  


  
}