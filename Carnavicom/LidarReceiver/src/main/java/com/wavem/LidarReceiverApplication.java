package com.wavem;

import java.io.IOException;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationEvent;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.event.EventListener;

import com.wavem.service.MulticastEchoServer;

@SpringBootApplication(scanBasePackages = {"com.wavem.*"})
@MapperScan(basePackages = {"com.wavem.persistence"})
public class LidarReceiverApplication {

	@Autowired
	public MulticastEchoServer server;

	public static void main(String[] args) {
		
		ConfigurableApplicationContext ac = SpringApplication.run(LidarReceiverApplication.class, args);
		//ac.publishEvent(new UdpRunEvent(ac,"UDP RUN EVENT"));	        
	}
	
	 @PostConstruct
	 public void RunUdpReciever() {
		 try {

			server.start();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	 }
	
	 @PreDestroy
	 public void DestroyUdpReciever() {
		 try {

			Thread.sleep(1);
			server.interrupt();
			
			System.out.println("Destroy Server");
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	 }
		/*
		 
		@EventListener(UdpRunEvent.class)
		public void onMyEvent(UdpRunEvent event){
			//System.out.println("EventListener : " + event.getMessage());
			//MulticastEchoServer server;
			try {
			//	server = new MulticastEchoServer();
				server.start();
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		
		
		static class UdpRunEvent extends ApplicationEvent 
		{
			private final String message; 
			public UdpRunEvent(Object source, String message) { 
			   super(source); 
			   this.message = message; 
			} 
			
			public String getMessage(){ 
				return message;  
		    }
		}*/
	
}
