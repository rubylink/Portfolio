public class Song extends Content{

  public Song(){
    super();
  }
  public Song(String t, String a){
    super(t,a);
  }

  public String getSongTitle(){
    return m_title;
  }

  public boolean equals(Object o) {
    if (this == o) { // checks memory locations
      return true;
    }
    if (!(o instanceof Song)) {
      return false;
    }
    Song s = (Song) o;
    return super.equals(o);
  }

  public void play(){ 
    this.m_numStreams += 1; 
    //System.out.println("You have played this song " + m_numStreams + " times");
  }
  
  public String toString() {
    String s = super.toString(); 
    s += "Number of streams: "+ m_numStreams +"\n";
    return s;
  }

  }