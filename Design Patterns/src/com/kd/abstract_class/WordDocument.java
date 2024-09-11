package com.kd.abstract_class;

public class WordDocument extends Document {

  @Override
  public void save() {
    System.out.println("Saving the document");
  }
}
