#Get ThingML (at a given commit) and compile it
FROM maven:3-jdk-8-slim

ARG SHA=30d4c4dd6f5986d190412bc3a19f5517c956b6d7

COPY ./settings.xml settings.xml

RUN curl --silent -O -J -L https://github.com/TelluIoT/ThingML/archive/$SHA.zip && unzip -qq ThingML-$SHA.zip -d . && rm ThingML-$SHA.zip 

WORKDIR ThingML-$SHA

RUN mvn -q -s ../settings.xml -DskipTests clean install && mv compilers/official-network-plugins/target/*-jar-with-dependencies.jar /thingml.jar 



FROM openjdk:8-jre-slim

COPY --from=0 thingml.jar thingml.jar

RUN chmod +x thingml.jar

ENTRYPOINT ["java", "-jar", "thingml.jar"]
CMD ["-h"]
