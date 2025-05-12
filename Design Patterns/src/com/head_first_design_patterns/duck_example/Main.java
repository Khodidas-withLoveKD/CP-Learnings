package com.head_first_design_patterns.duck_example;

import com.head_first_design_patterns.duck_example.ducks.Duck;
import com.head_first_design_patterns.duck_example.ducks.MallardDuck;

public class Main {
    public static void main(String[] args) {
        Duck mallardDuck = new MallardDuck();

        mallardDuck.performFly();
        mallardDuck.performQuack();
    }
}
