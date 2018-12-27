[![npm](https://img.shields.io/npm/v/bs-winston-cloudwatch.svg)](https://www.npmjs.com/package/bs-winston-cloudwatch)


# BsWinstonCloudwatch

Adapter of [winston-cloudwatch](https://github.com/lazywithclass/winston-cloudwatch) winston transport plugin for ReasonML. Used with [BsWinston](https://github.com/veikkaus/bs-winston).

# Install

```
npm install bs-winston-cloudwatch
```
And to `bsconfig.json`: `"bs-dependencies": [..., "bs-winston-cloudwatch", ...]`

`bs-winston` must naturally be installed also.

# Examples

```
let (cloudwatchTransport, kthxbyeFn) = BsWinstonCloudwatch.Transport.createCloudwatch(
  ~logGroupName = "xxxx",
  ~logStreamName = "yyyy",
);

let logger = Builder.create()
  -> Builder.addTransport(cloudwatchTransport)
  -> Builder.build;

/*  ... after logging done, flush and close:  */
kthxbye();

```