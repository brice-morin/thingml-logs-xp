#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# See the NOTICE file distributed with this work for additional
# information regarding copyright ownership.
#

FROM debian:stretch-slim

ENV JAVA_HOME /opt/graalvm
ENV GRAALVM_HOME /opt/graalvm
ENV NATIVE_IMAGE_CONFIG_FILE $GRAALVM_HOME/native-image.properties
ENV PATH /opt/apache-maven/bin:$JAVA_HOME/jre/bin:$GRAALVM_HOME/bin:$PATH
# All in one step, to reduce number of layers
RUN apt-get update &&     apt-get -y install gcc libc6-dev zlib1g-dev curl &&     curl https://archive.apache.org/dist/maven/maven-3/3.6.3/binaries/apache-maven-3.6.3-bin.tar.gz -o /tmp/maven.tar.gz &&     tar -zxvf /tmp/maven.tar.gz -C /tmp &&     mv /tmp/apache-maven-3.6.3 /opt/apache-maven &&     curl -L https://github.com/oracle/graal/releases/download/vm-19.1.1/graalvm-ce-linux-amd64-19.1.1.tar.gz -o /tmp/graalvm.tar.gz &&     tar -zxvf /tmp/graalvm.tar.gz -C /tmp &&     mv /tmp/graalvm-ce-19.1.1 /opt/graalvm &&     echo "JavaArgs = -Xmn512k" >> $NATIVE_IMAGE_CONFIG_FILE &&     echo "Args = -H:Kind=EXECUTABLE" >> $NATIVE_IMAGE_CONFIG_FILE &&     mkdir -p /root/.native-image &&     rm -rf /var/lib/apt/lists/* &&     rm -rf /tmp/*
COPY . .
RUN curl -L https://github.com/TelluIoT/ThingML/releases/download/1.0.0/mvn_repo_generated.tar.gz -o ./mvn_repo_generated.tar.gz &&     tar -xzf mvn_repo_generated.tar.gz &&     rm mvn_repo_generated.tar.gz &&     mvn install && mv target/org.thingml.generated.main /app && rm -rf target
#FROM scratch
FROM debian:stretch-slim
COPY --from=0 app /app





CMD ["./app"]