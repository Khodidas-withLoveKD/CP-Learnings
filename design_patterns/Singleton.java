package design_patterns;

// Only one instance of this is maintained and a global point of access is given for it
public class Singleton {
  private static Singleton instance;

  private Singleton() {}

  public static Singleton getInstance() {
    if (instance == null) {
      instance = new Singleton();
    }

    return instance;
  }

  public void getMessage() {
    System.out.println("THIS IS A message");
  }
}

