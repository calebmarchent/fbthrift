<?hh // strict
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift exception:-
 * Banal
 */
class Banal extends \TException implements \IThriftStruct {
  use \ThriftSerializationTrait;

  public static dict<int, dict<string, mixed>> $_TSPEC = dict[
    ];
  public static Map<string, int> $_TFIELDMAP = Map {
  };
  const int STRUCTURAL_ID = 957977401221134810;

  <<__Rx>>
  public function __construct(  ) {
    parent::__construct();
  }

  public function getName(): string {
    return 'Banal';
  }

}

/**
 * Original thrift exception:-
 * Fiery
 */
class Fiery extends \TException implements \IThriftStruct {
  use \ThriftSerializationTrait;

  public static dict<int, dict<string, mixed>> $_TSPEC = dict[
    1 => dict[
      'var' => 'message',
      'type' => \TType::STRING,
      ],
    ];
  public static Map<string, int> $_TFIELDMAP = Map {
    'message' => 1,
  };
  const int STRUCTURAL_ID = 1438368398389181198;
  /**
   * Original thrift field:-
   * 1: string message
   */
  public string $message;

  <<__Rx>>
  public function __construct(?string $message = null  ) {
    parent::__construct();
    if ($message === null) {
      $this->message = '';
    } else {
      $this->message = $message;
    }
  }

  public function getName(): string {
    return 'Fiery';
  }

}

/**
 * Original thrift exception:-
 * Serious
 */
class Serious extends \TException implements \IThriftStruct {
  use \ThriftSerializationTrait;

  public static dict<int, dict<string, mixed>> $_TSPEC = dict[
    1 => dict[
      'var' => 'sonnet',
      'type' => \TType::STRING,
      ],
    ];
  public static Map<string, int> $_TFIELDMAP = Map {
    'sonnet' => 1,
  };
  const int STRUCTURAL_ID = 7572301088987666687;
  /**
   * Original thrift field:-
   * 1: string sonnet
   */
  public ?string $sonnet;

  <<__Rx>>
  public function __construct(?string $sonnet = null  ) {
    parent::__construct();
    $this->sonnet = $sonnet;
  }

  public function getName(): string {
    return 'Serious';
  }

  <<__Override>>
  public function getMessage(): string {
    return $this->sonnet ?? '';
  }

}

