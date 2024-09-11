package com.kd;

import com.kd.abstract_class.WordDocument;

public class Main {
  private static void singleton() {
    Singleton singleton = Singleton.getInstance();
    singleton.showMessage();
    Singleton singleton2 = Singleton.getInstance();
    singleton2.showMessage();
  }

  private static void abstractClassExample() {
    WordDocument wordDocument = new WordDocument();
    wordDocument.open();
    wordDocument.save();
    wordDocument.close();
  }

  public static void main(String[] args) {

//    singleton();
    abstractClassExample();
  }
}