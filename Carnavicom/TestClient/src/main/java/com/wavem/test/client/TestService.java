package com.wavem.test.client;

import java.util.Iterator;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

import com.wavem.lidar.DistanceData;
import com.wavem.vo.DistanceDataVO;

@Component
public class TestService{

	private static final Logger logger = LoggerFactory.getLogger(TestService.class);
	
	public void run() throws Exception {
		
		DistanceData data = new DistanceData("http","127.0.0.1:8089");
		List<DistanceDataVO> dataList = data.getDistanceData("20220304134401712");
		
		if ( dataList == null ) {
		    logger.info("result is null");
		    return;
		}
			
		Iterator<DistanceDataVO> iterator = dataList.listIterator();
        try{
            while (iterator.hasNext()) {
                
            	DistanceDataVO d_vo = iterator.next();
                if (d_vo == null)
                    break;
                
                logger.info(d_vo.getDetectionTime() + " - [" + d_vo.getRangeIndex()+ "]" + d_vo.getRangeData()  );
                
                    
            }
        }catch(Exception e){
            logger.error(e.getMessage());           
            for (StackTraceElement element : e.getStackTrace()) {
                logger.error(element.toString());
            }
        }
	}
}
