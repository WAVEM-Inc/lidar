/*package com.wavem;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

import java.io.IOException;
import com.wavem.service.MulticastEchoServer;


@Component
public class CommandLineAppStartupRunner implements CommandLineRunner {
    private static final Logger LOG = LoggerFactory.getLogger(CommandLineAppStartupRunner.class);
    
    @Override
    public void run(String...args) throws Exception {
    	System.out.println("Server Start");
		
		try {
		    MulticastEchoServer server = new MulticastEchoServer();
			server.start();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }

}*/
