package com.kd.abstract_class;

// abstract class - which cannot be instantiated
abstract class Document {

  // abstract class which has to be implemented by its subclass
  abstract void save();

  // concrete methods which is common to all instances
  public void open() {
    System.out.println("Opening the doc");
  }

  public void close() {
    System.out.println("Closing the doc");
  }
}
