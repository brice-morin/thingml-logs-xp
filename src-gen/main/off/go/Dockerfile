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

FROM golang:alpine

RUN mkdir -p /go/src/test
WORKDIR /go/src/test
RUN apk add --no-cache build-base git
RUN go get github.com/SINTEF-9012/gosm
COPY . .
RUN go build -ldflags "-linkmode external -extldflags -static" -o test -a *.go
FROM scratch
COPY --from=0 /go/src/test/test /test





CMD ["/test"]