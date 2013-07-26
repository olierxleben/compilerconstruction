#!/usr/bin/env ruby

# USAGE: ./server.rb path/to/the/root/dir

require 'rubygems'
require 'rack' # rack it up

serve = Rack::Builder.new do
 use Rack::Static, 
   :urls => ["/images", "/js", "/css"],
   :root => ARGV[0],
   :index => 'index.html'
 run Rack::File.new(ARGV[0])
end

# by default WEBrick doesen`t listen to sigkill, cause the script runs in a new session. 
Signal.trap('INT') {
  Rack::Handler::WEBrick.shutdown
}

# takeoff
Rack::Handler::WEBrick.run(serve, :port => 8080, 'Contetn-Type'=>'text/html')