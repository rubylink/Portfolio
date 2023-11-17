public abstract class Account{
  protected String m_username;

  public Account(){
    m_username = null;
  }

  public Account(String name){
    m_username = name;
  }

  public String getUsername(){
    return m_username;
  }

  public String toString(){
    String s = "";
    s += m_username;
    return s; 
  }


  
}