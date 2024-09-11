package com.kd;

public class Singleton {
  private Singleton() {}
  private static Singleton instance;

  public static Singleton getInstance() {
    if (instance == null) {
      instance = new Singleton();
    }

    return instance;
  }

  public void showMessage() {
    System.out.println("Hello from Singleton!!!");
  }
}
