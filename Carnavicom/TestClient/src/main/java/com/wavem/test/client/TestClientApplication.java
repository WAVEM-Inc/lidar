package com.wavem.test.client;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class TestClientApplication {

	public static void main(String[] args) {
		
      TestService svc = new TestService();
      
      try {
		svc.run();
      } catch (Exception e) {
		e.printStackTrace();
      }
	}

}
