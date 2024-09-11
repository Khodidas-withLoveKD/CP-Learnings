package design_patterns;

public class Main {
  public static void main(String[] args) {

    Singleton singleton = Singleton.getInstance();
    singleton.getMessage();
  }
}
