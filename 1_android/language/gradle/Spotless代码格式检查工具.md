# spotless代码格式检查工具
Github地址：https://github.com/diffplug/spotless/tree/main/plugin-gradle#ktlint

## 接入方式
```
buildscript {
    dependencies {
        classpath 'com.diffplug.spotless:spotless-plugin-gradle:5.14.0'
    }
}

apply plugin: 'com.diffplug.spotless'

spotless {
    kotlin {
        ktlint('0.39.0').userData([
                'indent_size': '2',
                'kotlin_imports_layout': 'ascii',
                'disabled_rules': 'no-wildcard-imports'
        ])
    }
}
```